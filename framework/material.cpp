#include "material.hpp"

Material::Material(): _name{"untitled_material"}, _ka{1.0f,1.0f,1.0f}, _kd{1.0f, 1.0f, 1.0f}, _ks{1.0f, 1.0f, 1.0f}, _m{0}, _refl{0}, _refr{0}, _opacity{0}
{}

Material::Material(std::string name, Color const& ka, Color const& kd,Color const& ks, float m, float refl, float refr, float o): _name{name}, _ka{ka}, _kd{kd}, _ks{ks}, _m{m}, _refl{refl}, _refr{refr}, _opacity{o}
{}

Material::~Material()
{}

	Color Material::ka() const
	{
		return _ka;
	}

	Color Material::kd() const
	{
		return _kd;
	}

	Color Material::ks() const
	{
		return _ks;
	}

	float Material::m() const
	{
		return _m;
	}

	float Material::refl() const
	{
		return _refl;
	}

	float Material::refr() const
	{
		return _refr;
	}

	float Material::opacity() const
	{
		return _opacity;
	}

	std::string Material::name() const
	{
		return _name;
	}

	std::ostream& operator<<(std::ostream& os , Material const& ma)
	{
		os << "[" << ma._name << ma._ka << "," << ma._kd << "," << ma._ks << "," << ma._m << "]";
	}