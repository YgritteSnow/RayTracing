#ifndef __RAYTRACING_RAYTRACE_MODEL_H__
#define __RAYTRACING_RAYTRACE_MODEL_H__
#include <d3dx9math.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

namespace RayTrace
{
	/************************************************************************/
	/* 光线                                                                     */
	/************************************************************************/
	class ICollideLine
	{
	public:
		virtual D3DXVECTOR3 GetNormal() const = 0;
		virtual D3DXVECTOR3 GetStartPoint() const = 0;
		virtual float GetLength() const = 0;
		virtual float GetLenghtSqr() const = 0;
	};

	class CCollideLine : public ICollideLine
	{
	public:
		virtual D3DXVECTOR3 GetNormal() const;
		virtual D3DXVECTOR3 GetStartPoint() const {return m_start;};
		virtual float GetLength() const {return D3DXVec3Length(&(m_end - m_start));};
		virtual float GetLenghtSqr() const {return D3DXVec3LengthSq(&(m_end - m_start));};

	private:
		D3DXVECTOR3 m_start;
		D3DXVECTOR3 m_end;
	};

	/************************************************************************/
	/* 模型                                                                     */
	/************************************************************************/
	class ICollideModel
	{
	public:
		virtual bool IsCollide(const ICollideLine& line, D3DXVECTOR3* out_collidePoint) const = 0;
	};

	class CCollildeBall
	{
	public:
		virtual bool IsCollide(const ICollideLine& line, D3DXVECTOR3* out_collidePoint) const;

	protected:
		bool CalLineCross(const ICollideLine& line, D3DXVECTOR3* out_collidePoint, float* out_collideLengthProj, float* out_collideLengthHalf) const;

	private:
		D3DXVECTOR3 m_center;
		float m_radius;
	};

	class CCollideRectangle : public ICollideModel
	{
	public:
		virtual bool IsCollide(const ICollideLine& line, D3DXVECTOR3* out_collidePoint) const;

	protected:
		virtual const D3DXVECTOR3& GetNormal() const;
		virtual D3DXVECTOR3 GetWidthNormal() const;
		virtual D3DXVECTOR3 GetHeightNormal() const;

		bool CalLineCross(const ICollideLine& line, D3DXVECTOR3* out_collidePoint) const;

	private:
		D3DXVECTOR3 m_normal;
		D3DXVECTOR3 m_widthnormal;
		D3DXVECTOR3 m_center;
		float m_width;
		float m_height;
	};

	/************************************************************************/
	/* 光源                                                                     */
	/************************************************************************/
	class ICollideLight
	{
	public:
		virtual const D3DXVECTOR3& GetPosition() const = 0;
	};

	class CCollideLightPoint
	{
	public:
		virtual const D3DXVECTOR3& GetPosition() const {return m_position;}
	private:
		D3DXVECTOR3 m_position;
		float m_factorA;
	};

}
#endif 