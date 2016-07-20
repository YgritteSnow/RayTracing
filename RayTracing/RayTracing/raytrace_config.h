
namespace RayTrace
{
	extern const float c_max_dist;
	bool IsMaxDist(float d){return d > c_max_dist - 0.1;}

	extern const int c_max_recurDepth;
	bool IsMaxRecurDepth(int r){return r >= c_max_recurDepth;}

	enum { c_screen_width = 400 };
	enum { c_screen_height = 300 };
}