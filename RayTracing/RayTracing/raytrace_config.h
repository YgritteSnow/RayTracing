#ifndef __RAYTRACING_RAYTRACE_CONFIG_H__
#define __RAYTRACING_RAYTRACE_CONFIG_H__
namespace RayTrace
{
	extern const float c_max_dist;
	extern bool IsMaxDist(float d);

	extern const int c_max_recurDepth;
	extern bool IsMaxRecurDepth(int r);

	enum { c_screen_width = 400 };
	enum { c_screen_height = 300 };
}
#endif 