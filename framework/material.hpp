#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP
#include <string>
#include <iostream>
#include <color.hpp>

class Material
{	
public:
	//Constructor
	Material();
	Material(std::string name, Color const& ka, Color const& kd,Color const& ks, float m);
	~Material();

	Color ka() const;

	Color kd() const;

	Color ks() const;

	float m() const;

	std::string name() const;

	friend std::ostream& operator<<(std::ostream& os, Material const& ma);

	private:
		Color _ka;
		Color _kd;
		Color _ks;
		std::string _name;
		float _m;
};

#endif // BUW_MATERIAL_HPP
