"""Launch the opengl node"""

import pathlib
import os.path as osp
from launch import LaunchDescription
import launch_ros.actions

opengl_share_dir = pathlib.Path(__file__).resolve().parent

parameters=[]

var = ""

def get_opengl_node():
    # If needed one could add variant depending parameters here
    # if var == "":
    #     parameters=[str(opengl_share_dir)+"/name.yaml"]
    # else:
    #     parameters=[str(opengl_share_dir)+"/name2.yaml"]


    return launch_ros.actions.Node(
                package="opengl_node",
                executable="opengl_node",
                output="screen",
                namespace="/"
                #parameters=parameters
            )

