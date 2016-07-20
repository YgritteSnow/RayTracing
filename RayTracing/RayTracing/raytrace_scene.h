#ifndef __RAYTRACING_RAYTRACE_SCENE_H__
#define __RAYTRACING_RAYTRACE_SCENE_H__

#include <vector>
#include <d3dx9math.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

#include "raytrace_model.h"
#include "raytrace_config.h"

namespace RayTrace
{

	class Scene
	{
	public:
		void GenerateRayTrace();

	private:
		bool CalPixel_byRay(const ICollideRay& ray, D3DXCOLOR* out_color, int recurDepth) const ;
		D3DXCOLOR CalLights(D3DXVECTOR3* pos) const ;
		
		void CalReflectRay( const D3DXVECTOR3& collidePoint, const D3DXVECTOR3& collideNormal, const D3DXVECTOR3& collideRay, ICollideRay* out_reflectRay) const ;
		void CalRefractRay( const D3DXVECTOR3& collidePoint, const D3DXVECTOR3& collideNormal, const D3DXVECTOR3& collideRay, ICollideRay* out_reflectRay) const ;

		CCollideRay CalCameraRay( int screen_x, int screen_y ) const ;

	private:
		D3DXCOLOR m_imgData[c_screen_width][c_screen_height];

		std::vector<ICollideLight*> m_vec_light;
		std::vector<ICollideModel*> m_vec_model;
	};

}
#endif 