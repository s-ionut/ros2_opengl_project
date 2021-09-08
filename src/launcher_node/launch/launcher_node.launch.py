"""Launch OPENGL nodes"""

import os
import ament_index_python
import pathlib
import os.path as osp
from launch import LaunchDescription
import launch_ros.actions
import argparse
import sys

def generate_launch_description():
	print("[INFO] LAUNCHING OPENGL PROJECT")

	#OPENGL_NODE
	sys.path.append(os.path.join(ament_index_python.get_package_share_directory('opengl_node'),"launch"))
	from opengl_node import get_opengl_node

	launch_description = LaunchDescription(
	[
		get_opengl_node()
	]
	)

	return launch_description
