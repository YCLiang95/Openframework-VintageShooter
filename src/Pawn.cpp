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
	Pawn* result = new Pawn(*this);
	return result;
}

 bool Pawn::collide(Pawn* A, Pawn* B) {
	if (A->collisionLayer == B->collisionLayer)
		return Transform::collide(A->transform, B->transform);
}
