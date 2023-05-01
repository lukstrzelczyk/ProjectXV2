#include "Stryker.h"

Stryker::Stryker(std::string v, std::string arm, size_t no, size_t id, size_t w, size_t s, size_t ft, size_t f, std::string t, size_t c)
	:
	Vehicle(w, s, ft, f, t, c), version{ v }, armament{ arm }, number_of_carried_soldiers{ no },
	ID{ id }
{
	engine = new Diesel;
}

Stryker::Stryker(const Stryker& clone):ID{clone.ID},Vehicle{clone.get_weight(),clone.get_speed(),
clone.get_max_range(),clone.get_range(),clone.get_type(),clone.get_crew()}
{
	delete engine;
	version = clone.version;
	armament = clone.armament;
	number_of_carried_soldiers = clone.number_of_carried_soldiers;
	engine = new Diesel{ clone.engine->get_name(),clone.engine->get_p(),clone.engine->get_w(),clone.engine->get_t() };
}

Stryker::~Stryker()
{
	delete engine;
	engine = nullptr;
	
}

