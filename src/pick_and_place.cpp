#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char** argv)
{
  // Initialisation ROS2
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("pick_and_place");

  // Interfaces MoveIt2 pour le bras et la pince
  moveit::planning_interface::MoveGroupInterface arm(node, "arm");
  moveit::planning_interface::MoveGroupInterface gripper(node, "gripper");

  RCLCPP_INFO(node->get_logger(), "Pick and Place node started");

  // Aller en position "home"
  arm.setNamedTarget("home");
  arm.move();
  RCLCPP_INFO(node->get_logger(), "Arm moved to home position");

  // Aller vers l’objet (par ex. une boîte devant le robot)
  geometry_msgs::msg::Pose target_pose;
  target_pose.orientation.w = 1.0;
  target_pose.position.x = 0.5;   // position de la boîte
  target_pose.position.y = 0.0;
  target_pose.position.z = 0.5;
  arm.setPoseTarget(target_pose);
  arm.move();
  RCLCPP_INFO(node->get_logger(), "Arm moved to object pose");

  // Fermer la pince
  gripper.setNamedTarget("close");
  gripper.move();
  RCLCPP_INFO(node->get_logger(), "Gripper closed");

  // Déplacer vers la zone de dépôt
  target_pose.position.x = 1.0;   // zone verte
  target_pose.position.y = 0.0;
  target_pose.position.z = 0.5;
  arm.setPoseTarget(target_pose);
  arm.move();
  RCLCPP_INFO(node->get_logger(), "Arm moved to drop zone");

  // Ouvrir la pince
  gripper.setNamedTarget("open");
  gripper.move();
  RCLCPP_INFO(node->get_logger(), "Gripper opened");

  // Fin
  rclcpp::shutdown();
  return 0;
}

