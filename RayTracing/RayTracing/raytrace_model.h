
#include <d3dx9math.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

namespace RayTrace
{
	
	class ICollideLine
	{
	public:
		virtual const D3DXVECTOR3& GetNormal() const = 0;
	};

	class CollideLine : public ICollideLine
	{
	public:
		virtual const D3DXVECTOR3& GetNormal() const;

	private:
		D3DXVECTOR3 m_start;
		D3DXVECTOR3 m_end;
	};

	class ICollideModel : public ICollideModel
	{
	public:
		virtual bool IsCollide(const ICollideLine& line, D3DXVECTOR3* out_collidepoint) const = 0;
	};

	class CollildeBall
	{
	public:
		virtual bool IsCollide(const ICollideLine& line, D3DXVECTOR3* out_collidepoint) const;

	private:
		D3DXVECTOR3 m_center;
		float m_radius;
	};

	class CollideRectangle : public ICollideModel
	{
	public:
		virtual bool IsCollide(const ICollideLine& line, D3DXVECTOR3* out_collidepoint) const;

	protected:
		virtual const D3DXVECTOR3& GetNormal() const;
		virtual D3DXVECTOR3 GetWidthNormal() const;
		virtual D3DXVECTOR3 GetHeightNormal() const;
	private:
		D3DXVECTOR3 m_normal;
		D3DXVECTOR3 m_widthnormal;
		D3DXVECTOR3 m_center;
		float m_width;
		float m_height;
	};

}