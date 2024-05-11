#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/Quaternion.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include <cmath>
#include <tf/transform_datatypes.h>
#include "std_msgs/Bool.h"

#include "datmo.h"


#define waiting_for_a_person 0
#define observing_the_person 1
#define rotating_to_the_person 2
#define moving_to_the_person 3
#define interacting_with_the_person 4
#define rotating_to_the_base 5
#define moving_to_the_base 6
#define resetting_orientation 7

#define frequency_expected 25
#define max_base_distance 6

class decision_node
{
private:

    ros::NodeHandle n;

    // communication with datmo_node
    ros::Subscriber sub_person_position;
    bool new_person_position, person_tracked;
    geometry_msgs::Point person_position, previous_position;

    // communication with robot_moving_node
    ros::Subscriber sub_robot_moving;
    bool robot_moving;

    // communication with rotation_action
    ros::Publisher pub_rotation_to_do;
    float rotation_to_person;


    // communication with action_node
    ros::Publisher pub_goal_to_reach;
    float translation_to_person;

    // communication with localization
    ros::Subscriber sub_localization;
    bool new_localization;
    bool init_localization;
    geometry_msgs::Point current_position;
    float current_orientation;
    float translation_to_base;
    float rotation_to_base;
    geometry_msgs::Point local_base_position;

    int current_state, previous_state;
    int frequency;
    geometry_msgs::Point base_position;
    float base_orientation;
    geometry_msgs::Point origin_position;
    bool state_has_changed;

    float base_threshold = 0.05; 
    float translation_threshold = 0.20;



public:

decision_node()
{

    // communication with datmo_node
    sub_person_position = n.subscribe("person_position", 1, &decision_node::person_positionCallback, this);

    // communication with rotation_node
    pub_rotation_to_do = n.advertise<geometry_msgs::Point>("rotation_to_do", 1);      // Preparing a topic to publish a rotation to perform

    // communication with action_node
    pub_goal_to_reach = n.advertise<geometry_msgs::Point>("goal_to_reach", 1);     // Preparing a topic to publish the goal to reach

    // communication with robot_moving_node
    sub_robot_moving = n.subscribe("robot_moving", 1, &decision_node::robot_movingCallback, this);

    // communication with localization node
    sub_localization = n.subscribe("localization", 1, &decision_node::localizationCallback, this);

    current_state = waiting_for_a_person;
    previous_state = -1;

    new_person_position = false;
    state_has_changed = false;

    // TO COMPLETE:
    // Define base_position coordinates according to the chosen base / initial position in the map frame.

    while (!init_localization);  
    base_position.x = current_position.x;
    base_position.y = current_position.y;
    base_orientation = current_orientation;

    origin_position.x = 0;
    origin_position.y = 0;

    previous_position = origin_position;

    person_tracked = false;

    //INFINITE LOOP TO COLLECT LASER DATA AND PROCESS THEM
    ros::Rate r(10);// this node will work at 10hz
    while (ros::ok())
    {
        ros::spinOnce();// For each subscribed topic on which a message has been received, the corresponding callback function is called.
        update();
        r.sleep();//we wait if the processing (ie, callback+update) has taken less than 0.1s (ie, 10 hz)
    }

}

//UPDATE:  main processing function.
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void update()
{

    if ( init_localization )
    {

        update_variables();

        // TO COMPLETE:
        // DO NOT FORGET that if robair is too far from its base (ie, its distance to the base is higher than max_base_distance),
        // then robair should stop to interact with the moving person and go back to its base. Where should we implement this?
        switch ( current_state )
        {
            case waiting_for_a_person:
                process_waiting_for_a_person();
                break;

            case observing_the_person:
                process_observing_the_person();
                break;

            case rotating_to_the_person:
                process_rotating_to_the_person();
                break;

            case moving_to_the_person:
                process_moving_to_the_person();
                break;

            case interacting_with_the_person:
                process_interacting_with_the_person();
                break;

            case rotating_to_the_base:
                process_rotating_to_the_base();
                break;

            case moving_to_the_base:
                process_moving_to_the_base();
                break;

            case resetting_orientation:
                process_resetting_orientation();
                break;
        }

    new_localization = false;
    new_person_position = false;

    state_has_changed = current_state != previous_state;
    previous_state = current_state;

    }
    else
        ROS_WARN("Initialize localization");

}// end update

void update_variables()
{

    if ( new_person_position )
    {
        translation_to_person = distancePoints(origin_position, person_position);

        if ( translation_to_person > 0 )
        {
            rotation_to_person = acos( person_position.x / translation_to_person );
            if ( person_position.y < 0 )
                rotation_to_person *=-1;
        }
        else
            rotation_to_person = 0;

        person_tracked = person_position.x != 0 || person_position.y != 0;
    }        

    if ( new_localization )
    {   
        // TO COMPLETE:
        // when we receive a new position(x, y, o) of robair in the map, we update:
        local_base_position.x = (base_position.x-current_position.x);
        local_base_position.y = (base_position.y-current_position.y);
        // translation_to_base: the translation that robair has to do to reach its base
        // rotation_to_base: the rotation that robair has to do to reach its base
        // local_base_position: the position of the base in the cartesian local frame of robot
    }

}

void process_waiting_for_a_person()
{
    // Initialization of the state
    if ( state_has_changed )
    {
        ROS_INFO("current_state: waiting_for_a_person");
        ROS_INFO("press enter to continue");
        // For debugging. Uncomment when satisfied with the state machine transitions.
    }

    // Processing of the state
    // As soon as we detect a moving person, we switch to the state "observing_the_person"
    
    if ( new_person_position )
        state_has_changed = true;
        current_state = observing_the_person;

}

void process_observing_the_person()
{
    // Initialization of the state
    if ( state_has_changed )
    {
        // Initialisation as state has changed
        ROS_INFO("current_state: observing_the_person");
        ROS_INFO("person_position: (%f, %f)", person_position.x, person_position.y);
        ROS_INFO("press enter to continue");
        frequency = 0;      
        previous_position = person_position;
    }

    
    // Processing of the state
    // Robair only observes and tracks the moving person

    if ( new_person_position )
    {
        if (distancePoints(person_position, base_position) > max_base_distance) {
            ROS_INFO("the person went out of the area");
            current_state = waiting_for_a_person;
            return;
        }

        ROS_INFO("person_position: (%f, %f)", person_position.x, person_position.y);
        if (distancePoints(person_position, previous_position) <= 0.15) {
            frequency++;
        } else {
            frequency = 0;
            previous_position = person_position;
        }
        // if the moving person does not move for a certain time (use frequency), we should switch to the state "rotating_to_the_person".
        if (frequency >= frequency_expected) current_state = rotating_to_the_person;
    } 
    if (!person_tracked) {
        ROS_INFO("robair loses the moving person");
        current_state = waiting_for_a_person;
    }

}

void process_rotating_to_the_person()
{
    // Initialization of the state
    if ( state_has_changed )
    {
        ROS_INFO("current_state: rotating_to_the_person");
        ROS_INFO("person_position: (%f, %f)", person_position.x, person_position.y);
        ROS_INFO("press enter to continue");
        getchar();
        frequency = 0;
    }

    // Processing of the state
    // Robair rotates to be facing towards the moving person
    if ( new_person_position )
    {
        ROS_INFO("person_position: (%f, %f)", person_position.x, person_position.y);
        // TO COMPLETE:
        // Robair should rotate to face the person.
        
        if (rotation_to_person > 0)
        {
            geometry_msgs::Point temp_rotate_person; 
            temp_rotate_person.x = cos(rotation_to_person);
            temp_rotate_person.y = sin(rotation_to_person);
            pub_rotation_to_do.publish(temp_rotate_person);
            frequency = 0;
        }
        
        // TO COMPLETE:
        // if robair is facing the person and the ROBOT does not move during a while (use frequency and robot_moving boolean), we switch to the state "moving_to_the_person"
        
        
        else 
        {
            if (!robot_moving){
                frequency++;
            }
            
            if (frequency >= frequency_expected){
                current_state = moving_to_the_person;
            }

        }
         
    }

    // TO COMPLETE:
    // what should robair do if it loses the moving person ?

    if (!person_tracked)
    {
        current_state = resetting_orientation;
    }

}

void process_moving_to_the_person()
{
    // Initialization of the state
    if ( state_has_changed )
    {
        ROS_INFO("current_state: moving_to_the_person");
        ROS_INFO("person_position: (%f, %f)", person_position.x, person_position.y);
        ROS_INFO("press enter to continue");
        getchar();
        frequency = 0;
    }

    // Processing of the state
    // Robair moves to be close to the moving person
    if ( new_person_position )
    {
        ROS_INFO("person_position: (%f, %f)", person_position.x, person_position.y);
        //TO COMPLETE
        // Robair should move towards the person_position

        if (translation_to_person > translation_threshold)
        {
            pub_goal_to_reach.publish(person_position);
            frequency = 0;

        }

        //TO COMPLETE
        // if robair is close to the moving person and the moving person does not move during a while (use frequency), we switch to the state "interacting_with_the_person"
        
        else 
        {
            if (!robot_moving){
                frequency++;
            }
            
            if (frequency >= frequency_expected){
                current_state = interacting_with_the_person;
            }

        }
        
        ROS_INFO("frequency: (%f)", frequency);

    }

    // TO COMPLETE
    // what should robair do if it loses the moving person ?

    if (!person_tracked){
        current_state = resetting_orientation;
    }

}

void process_interacting_with_the_person()
{
    
    // Initialization of the state
    if ( state_has_changed )
    {
        ROS_INFO("current_state: interacting_with_the_person");
        ROS_INFO("person_position: (%f, %f)", person_position.x, person_position.y);
        ROS_INFO("press enter to continue");
        getchar();
        frequency = 0;
    }

    // Processing of the state
    // Robair does not move and interacts with the moving person until the moving person goes away from robair
    if ( new_person_position )
    {
        ROS_INFO("person_position: (%f, %f)", person_position.x, person_position.y);
        // TO COMPLETE:
        // if the person goes away from robair, after a while (use frequency), we switch to the state "rotating_to_the_base"

        if (translation_to_person > 0.5) {
            frequency++;
        } else {
            frequency = 0;
        }
            
        if (frequency >= frequency_expected) {
            current_state = rotating_to_the_base;
        }
    }

    // TO COMPLETE:
    // what should robair do if it loses the moving person ?
    if (!person_tracked) {
        current_state = rotating_to_the_base;
    }
}

void process_rotating_to_the_base()
{

    if ( state_has_changed )
    {
        ROS_INFO("current_state: rotating_to_the_base");
        ROS_INFO("position of robair in the map: (%f, %f, %f)", current_position.x, current_position.y, current_orientation*180/M_PI);
        ROS_INFO("press enter to continue");
        getchar();
        frequency = 0;
    }

    // Processing of the state
    // Robair rotates to be face to its base
    if ( new_localization )
    {
        ROS_INFO("position of robair in the map: (%f, %f, %f)", current_position.x, current_position.y, current_orientation*180/M_PI);
        //TO COMPLETE
        // robair should rotate to align with the base position (requires expressing base position in the robot / laser frame)
        pub_rotation_to_do.publish(local_base_position)

        //TO COMPLETE
        // if robair is face to its base and does not move, after a while (use frequency), we switch to the state "moving_to_the_base"
        if (!robot_moving) {
            frequency++;
            if (frequency >= frequency_expected) {
                state_has_changed = true;
                current_state = moving_to_the_base;
            }
        }
    }

}

void process_moving_to_the_base()
{

    if ( state_has_changed )
    {
        ROS_INFO("current_state: moving_to_the_base");
        ROS_INFO("position of robair in the map: (%f, %f, %f)", current_position.x, current_position.y, current_orientation*180/M_PI);
        ROS_INFO("press enter to continue");
        getchar();
        frequency = 0;
    }

    // Processing of the state
    // Robair moves to its base
    if ( new_localization )
    {
        ROS_INFO("position of robair in the map: (%f, %f, %f)", current_position.x, current_position.y, current_orientation*180/M_PI);

        
        //TO COMPLETE:
        // robair should move towards the base point (requires expressing base position in robair frame)
        pub_goal_to_reach.publish(local_base_position);
        // TO COMPLETE:
        // if robair is close to its base and does not move, after a while (use frequency), we switch to the state "resetting_orientation"
        if (distancePoints(current_position, base_position) < base_threshold && !robot_moving) {
            frequency++;
            if (frequency >= frequency_expected) {
                state_has_changed = true;
                current_state = resetting_orientation;
            }
        }
    }

}

void process_resetting_orientation()
{

    if ( state_has_changed )
    {
        ROS_INFO("current_state: initializing_rotation");
        ROS_INFO("position of robair in the map: (%f, %f, %f)", current_position.x, current_position.y, current_orientation*180/M_PI);
        ROS_INFO("press enter to continue");
        getchar();
        frequency = 0;
    }

    // Processing of the state
    // Robair rotates to its initial orientation
    if ( new_localization )
    {
        ROS_INFO("position of robair in the map: (%f, %f, %f)", current_position.x, current_position.y, current_orientation*180/M_PI);
        //TO COMPLETE:
        // robair should rotate to face the initial orientation

        //---------------------------------------------

        float temp = current_orientation;
        if ( temp > M_PI )
        {
            temp -= 2*M_PI;
        }
        else{
            if ( temp < -M_PI )
            {
                temp += 2*M_PI;
            }
        }
        
        geometry_msgs::Point temp_local_base; 
        temp_local_base.x = cos(temp);
        temp_local_base.y = sin(temp);

        pub_goal_to_reach.publish(temp_local_base);

        //------------------------------------------

        //TO COMPLETE
        // if robair is close to its initial orientation and does not move, after a while (use frequency), we switch to the state "waiting_for_a_person"
        
        if (abs(current_orientation - base_orientation) < base_threshold && !robot_moving) {
            frequency++;
        }
        if (frequency >= frequency_expected) {
            state_has_changed = true;
            current_state = waiting_for_a_person;
        }
    }
}

//CALLBACKS
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void person_positionCallback(const geometry_msgs::Point::ConstPtr& g)
{
// process the goal received from moving_persons detector

    new_person_position = true;
    person_position.x = g->x;
    person_position.y = g->y;

}

void robot_movingCallback(const std_msgs::Bool::ConstPtr& state)
{

    robot_moving = state->data;

}//robot_movingCallback

void localizationCallback(const geometry_msgs::Point::ConstPtr& l)
{
// process the localization received from my localization

    new_localization = true;
    init_localization = true;
    current_position = *l;
    current_orientation = l->z;

}

// Distance between two points
float distancePoints(geometry_msgs::Point pa, geometry_msgs::Point pb) {

    return sqrt(pow((pa.x-pb.x),2.0) + pow((pa.y-pb.y),2.0));

}

};

int main(int argc, char **argv)
{

    ROS_INFO("(decision_node) waiting for a /person_position");
    ros::init(argc, argv, "decision_node");

    decision_node bsObject;

    ros::spin();

    return 0;

}
