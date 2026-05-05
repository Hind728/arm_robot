# 🦾 ARM Robot — Pick & Place with ROS2 & MoveIt2

A 6-DOF robotic arm simulation built with ROS2, Gazebo, and MoveIt2, capable of autonomously picking up objects and placing them at target locations.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Architecture](#architecture)
- [Known Issues](#known-issues)
- [Author](#author)

---

## Overview

This project implements a **robotic arm simulation** in ROS2 that can:
- Visualize and simulate a 6-DOF arm in **Gazebo**
- Control joints using **ros2_control** (`joint_trajectory_controller` + `gripper_controller`)
- Execute autonomous **pick and place** sequences using **MoveIt2**

---

## Features

- ✅ Full robot simulation in **Gazebo**
- ✅ URDF/Xacro robot description with joints and gripper
- ✅ `ros2_control` integration for joint & gripper control
- ✅ Manual joint control via trajectory controller
- ✅ `pick_and_place.cpp` node for autonomous sequences
- 🔧 MoveIt2 motion planning (in progress)

---

## Project Structure

\`\`\`
ros2_ws/
└── src/
    └── arm_robot/
        ├── urdf/
        │   └── arm.urdf.xacro
        ├── launch/
        │   └── start.launch.py
        ├── config/
        │   └── arm_controllers.yaml
        └── src/
            └── pick_and_place.cpp
\`\`\`

---

## Requirements

| Dependency | Version |
|---|---|
| ROS2 | Humble / Iron |
| Gazebo | Classic or Ignition |
| ros2_control | Latest |
| MoveIt2 | Latest |
| C++ | 17+ |

---

## Installation

\`\`\`bash
git clone https://github.com/Hind728/arm_robot.git ~/ros2_ws/src/arm_robot
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
source install/setup.bash
\`\`\`

---

## Usage

\`\`\`bash
# Launch simulation
ros2 launch arm_robot start.launch.py

# Activate controllers
ros2 control load_controller --set-state active joint_trajectory_controller
ros2 control load_controller --set-state active gripper_controller

# Run pick and place
ros2 run arm_robot pick_and_place
\`\`\`

---

## Known Issues

- ⚠️ `pick_and_place` node fails if `robot_description` is not published before launch.
- ⚠️ MoveIt2 cannot build the robot model if the URDF is not loaded via `xacro` correctly.

---

## Author

**Hind Kaznoun**  
GitHub: [@Hind728](https://github.com/Hind728)  
Email: hindkanoun05@gmail.com
