echo "[INFO]: SOURCING ROS2 SETUP"
source ~/ros2_galactic/ros2-linux/local_setup.bash > /dev/null 2>&1

echo "[INFO]: SOURCING OPENGL_NODE SETUP"
source ../bin/install/local_setup.bash > /dev/null 2>&1

echo "[INFO]: STARTING OPENGL_NODE"
ros2 launch launcher_node launcher_node.launch.py
