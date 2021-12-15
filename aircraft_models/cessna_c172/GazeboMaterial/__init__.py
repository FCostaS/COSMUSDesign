from GazeboMaterialFile import *
from GazeboMaterialItem import *


# Example content
def _getTestContent():
	return """
import * from "grid.material"

vertex_program Gazebo/DepthMapVS glsl
{
  source depth_map.vert

  default_params
  {
    param_named_auto texelOffsets texel_offsets
  }
}
fragment_program Gazebo/DepthMapFS glsl
{
  source depth_map.frag

  default_params
  {
    param_named_auto pNear near_clip_distance
    param_named_auto pFar far_clip_distance
  }
}

material Gazebo/DepthMap
{
  technique
  {
    pass
    {
      vertex_program_ref Gazebo/DepthMapVS { }
      fragment_program_ref Gazebo/DepthMapFS { }
    }
  }
}

vertex_program Gazebo/XYZPointsVS glsl
{
  source depth_points_map.vert
}

fragment_program Gazebo/XYZPointsFS glsl
{
  source depth_points_map.frag

  default_params
  {
    param_named_auto width viewport_width
    param_named_auto height viewport_height
  }
}

material Gazebo/XYZPoints
{
  technique
  {
    pass pcd_tex
    {
      separate_scene_blend one zero one zero

      vertex_program_ref Gazebo/XYZPointsVS { }
      fragment_program_ref Gazebo/XYZPointsFS { }
    }
  }
}

material Gazebo/Grey
{
  technique
  {
    pass main
    {
      ambient .3 .3 .3  1.0
      diffuse .7 .7 .7  1.0
      specular 0.01 0.01 0.01 1.000000 1.500000
    }
  }
}
material Gazebo/Gray : Gazebo/Grey
{
}

"""


if __name__ == "__main__":
	gzMaterial = GazeboMaterialFile("/usr/share/gazebo-8/media/materials/scripts/gazebo.material");
	gzMaterial._parse(_getTestContent())
	c1, c2 = gzMaterial.getColor('Gazebo/Grey')[0], gzMaterial.getColor('Gazebo/Gray')[0]
	print(str(" ".join(c1.args())))


__all__ = ['GazeboMaterialItem', 'GazeboMaterialFile']
