#pragma once
#include "Engine.h"
#include "Papillon.h"
#include "Fourmi.h"
#include "Carre.h"
#include "Vaisseau.h"
#include "Chasseur.h"

class MyControlEngine:public ControlEngine {
    std::vector<Vaisseau * > *vaisseaux;
	std::vector<std::vector<Carre *> > carres;

public:
	MyControlEngine(std::vector<std::vector<Carre *> > carres_, std::vector<Vaisseau *> *vaisseaux_) :
		carres(carres_),
		vaisseaux(vaisseaux_)
		{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
