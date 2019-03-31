#include "Pawn.h"



Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}

void Pawn::update() {
	transform.update();
}

void Pawn::draw() {
	sprite->draw(transform);
}

Pawn* Pawn::clone() {
	cout << "Pawn clone" << endl;
	return NULL;
}
