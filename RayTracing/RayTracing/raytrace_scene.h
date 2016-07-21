#ifndef __RAYTRACING_RAYTRACE_SCENE_H__
#define __RAYTRACING_RAYTRACE_SCENE_H__

#include <vector>

#include "raytrace_model.h"

namespace RayTrace
{

	class Scene
	{
	private:
		std::vector<ICollideLight*> m_vec_light;
		std::vector<ICollideModel*> m_vec_model;
	};

}
#endif 