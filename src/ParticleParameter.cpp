#include "ParticleParameter.h"


ParticleParameter::ParticleParameter()
{	
	
	group.setName("Particles Parameters");
	
	group.add(color_diff_mult.set("Color Attraction", 0.1, 0.0, 1.0));
	group.add(collision_mult.set("Collision", 0.1, 0.0, 1.0));

	group.add(border_range.set("borderRange", 200, 0, 1000));

	group.add(drag.set("drag", 1.0, 0.0, 1.0));
	group.add(mass.set("mass", 1.0, 0.01, 4.0));

	group.add(spring_stiffness.set("springStiffness", 1.0, 0.0, 4.0));
	group.add(spring_damping.set("springDamping", 0.1, 0.0, 1.0));

}