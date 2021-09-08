echo "[INFO]: SOURCING ROS2 SETUP"
source ~/ros2_galactic/ros2-linux/local_setup.bash > /dev/null 2>&1

echo "[INFO]: BUILDING DEPENDENCIES"
#TODO

echo "[INFO]: SOURCING PROJECT SETUP"
source ../bin/install/local_setup.bash > /dev/null 2>&1

echo "[INFO]: BUILDING OPENGL_NODE PROJECT"
colcon --log-base "../bin/log" build --build-base "../bin/build" --install-base "../bin/install" --base-paths "../src" --cmake-clean-cache --event-handlers console_direct+ summary+
