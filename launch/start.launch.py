from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Lancer Gazebo directement avec ton monde
        ExecuteProcess(
            cmd=['gz', 'sim', '--verbose', 'worlds/arm_world.sdf'],
            output='screen'
        ),

        # Publier l'état du robot à partir de l'URDF
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            arguments=['urdf/arm.urdf.xacro']
        ),

        # Charger ros2_control
        Node(
            package='controller_manager',
            executable='ros2_control_node',
            parameters=['config/arm_controllers.yaml']
        ),

        # Ton nœud pick_and_place
        Node(
            package='arm_robot',
            executable='pick_and_place'
        ),
    ])
