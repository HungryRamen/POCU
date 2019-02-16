#include <cassert>
#include <iostream>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;
using namespace std;

int main()
{
	enum ID { A = 0, B, C, D, E, F, Z };
	const unsigned int WEIGHTS[] = { 85, 75, 52, 78, 48, 88, 0 };
	const char* NAMES[] = { "Bob", "James", "Tina", "Peter", "Jane", "Steve", "Bad" };
	Person* badMan = new Person(NAMES[Z], WEIGHTS[Z]);
	Person* p1 = new Person(NAMES[A], WEIGHTS[A]);
	assert(p1->GetName() == NAMES[A]);
	assert(p1->GetWeight() == WEIGHTS[A]);
	cout << "Test Person constructor: PASS" << endl;
	delete p1;

	Person* p2 = new Person(NAMES[A], WEIGHTS[A]);
	Person* p3 = new Person(NAMES[B], WEIGHTS[B]);
	Person* p4 = new Person(NAMES[C], WEIGHTS[C]);
	Person* p5 = new Person(NAMES[D], WEIGHTS[D]);
	Person* p6 = new Person(NAMES[E], WEIGHTS[E]);
	Person* p7 = new Person(NAMES[F], WEIGHTS[F]);
	Airplane a(5);
	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 0);
	cout << "Test Airplane constructor: PASS" << endl;

	assert(a.GetPassenger(B) == NULL);
	cout << "Test Airplane GetPassenger() - no passenger: PASS" << endl;
	assert(a.GetFlySpeed() == 991);
	cout << "Test Airplane GetFlySpeed() - no passenger: PASS" << endl;
	assert(a.GetDriveSpeed() == 1213);
	cout << "Test Airplane GetDriveSpeed() - no passenger: PASS" << endl;
	assert(a.GetMaxSpeed() == 1213);
	cout << "Test Airplane GetMaxSpeed() - no passenger: PASS" << endl;

	a.AddPassenger(p2);
	a.AddPassenger(p3);
	a.AddPassenger(p4);
	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	cout << "Test Airplane GetPassengersCount() - normal: PASS" << endl;
	assert(a.GetPassenger(B) == p3);
	cout << "Test Airplane GetPassenger() - normal: PASS" << endl;
	assert(a.GetFlySpeed() == 648);
	cout << "Test Airplane GetFlySpeed() - normal: PASS" << endl;
	assert(a.GetDriveSpeed() == 59);
	cout << "Test Airplane GetDriveSpeed() - normal: PASS" << endl;
	assert(a.GetMaxSpeed() == 648);
	cout << "Test Airplane GetMaxSpeed() - normal: PASS" << endl;

	Boat b(5);
	b.AddPassenger(p5);
	b.AddPassenger(p6);
	b.AddPassenger(p7);
	Boatplane bp = (a + b);
	assert(bp.GetPassengersCount() == 6);
	assert(bp.GetMaxPassengersCount() == 10);
	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);
	assert(bp.GetPassenger(A)->GetName() == p2->GetName());
	assert(bp.GetPassenger(A)->GetWeight() == p2->GetWeight());
	assert(bp.GetPassenger(B)->GetName() == p3->GetName());
	assert(bp.GetPassenger(B)->GetWeight() == p3->GetWeight());
	assert(bp.GetPassenger(C)->GetName() == p4->GetName());
	assert(bp.GetPassenger(C)->GetWeight() == p4->GetWeight());
	assert(bp.GetPassenger(D)->GetName() == p5->GetName());
	assert(bp.GetPassenger(D)->GetWeight() == p5->GetWeight());
	assert(bp.GetPassenger(E)->GetName() == p6->GetName());
	assert(bp.GetPassenger(E)->GetWeight() == p6->GetWeight());
	assert(bp.GetPassenger(F)->GetName() == p7->GetName());
	assert(bp.GetPassenger(F)->GetWeight() == p7->GetWeight());
	cout << "Test Airplane operator+() - normal: PASS" << endl;

	Person* p8 = new Person(NAMES[A], WEIGHTS[A]);
	Person* p9 = new Person(NAMES[B], WEIGHTS[B]);
	Person* p10 = new Person(NAMES[C], WEIGHTS[C]);
	Person* p11 = new Person(NAMES[D], WEIGHTS[D]);
	Person* p12 = new Person(NAMES[E], WEIGHTS[E]);
	Person* p13 = new Person(NAMES[F], WEIGHTS[F]);
	Boat b2(5);
	assert(b2.GetMaxPassengersCount() == 5);
	assert(b2.GetPassengersCount() == 0);
	cout << "Test Boat constructor: PASS" << endl;

	assert(b2.GetPassenger(B) == NULL);
	cout << "Test Boat GetPassenger() - no passenger: PASS" << endl;
	assert(b2.GetSailSpeed() == 800);
	cout << "Test Boat GetFlySpeed() - no passenger: PASS" << endl;
	assert(b2.GetMaxSpeed() == 800);
	cout << "Test Boat GetMaxSpeed() - no passenger: PASS" << endl;

	b2.AddPassenger(p8);
	b2.AddPassenger(p9);
	b2.AddPassenger(p10);
	assert(b2.GetMaxPassengersCount() == 5);
	assert(b2.GetPassengersCount() == 3);
	cout << "Test Boat GetPassengersCount() - normal: PASS" << endl;
	assert(b2.GetPassenger(B) == p9);
	cout << "Test Boat GetPassenger() - normal: PASS" << endl;
	assert(b2.GetSailSpeed() == 20);
	cout << "Test Boat GetFlySpeed() - normal: PASS" << endl;
	assert(b2.GetMaxSpeed() == 20);
	cout << "Test Boat GetMaxSpeed() - normal: PASS" << endl;

	Airplane a2(5);
	a2.AddPassenger(p11);
	a2.AddPassenger(p12);
	a2.AddPassenger(p13);
	Boatplane bp2 = (b2 + a2);
	assert(bp2.GetPassengersCount() == 6);
	assert(bp2.GetMaxPassengersCount() == 10);
	assert(a2.GetPassengersCount() == 0);
	assert(b2.GetPassengersCount() == 0);
	assert(bp2.GetPassenger(A)->GetName() == p11->GetName());
	assert(bp2.GetPassenger(A)->GetWeight() == p11->GetWeight());
	assert(bp2.GetPassenger(B)->GetName() == p12->GetName());
	assert(bp2.GetPassenger(B)->GetWeight() == p12->GetWeight());
	assert(bp2.GetPassenger(C)->GetName() == p13->GetName());
	assert(bp2.GetPassenger(C)->GetWeight() == p13->GetWeight());
	assert(bp2.GetPassenger(D)->GetName() == p8->GetName());
	assert(bp2.GetPassenger(D)->GetWeight() == p8->GetWeight());
	assert(bp2.GetPassenger(E)->GetName() == p9->GetName());
	assert(bp2.GetPassenger(E)->GetWeight() == p9->GetWeight());
	assert(bp2.GetPassenger(F)->GetName() == p10->GetName());
	assert(bp2.GetPassenger(F)->GetWeight() == p10->GetWeight());
	cout << "Test Boat operator+() - normal: PASS" << endl;

	Person* p14 = new Person(NAMES[A], WEIGHTS[A]);
	Person* p15 = new Person(NAMES[B], WEIGHTS[B]);
	Motorcycle m;
	assert(m.GetMaxPassengersCount() == 2);
	assert(m.GetPassengersCount() == 0);
	cout << "Test Motorcycle constructor: PASS" << endl;
	assert(m.GetDriveSpeed() == 400);
	cout << "Test Motorcycle GetDriveSpeed() - no passenger: PASS" << endl;
	assert(m.GetMaxSpeed() == 400);
	cout << "Test Motorcycle GetMaxSpeed() - no passenger: PASS" << endl;
	m.AddPassenger(p14);
	m.AddPassenger(p15);
	assert(m.GetPassengersCount() == 2);
	assert(m.GetPassenger(A)->GetName() == p14->GetName());
	assert(m.GetPassenger(A)->GetWeight() == p14->GetWeight());
	assert(m.GetPassenger(B)->GetName() == p15->GetName());
	assert(m.GetPassenger(B)->GetWeight() == p15->GetWeight());
	cout << "Test Motorcycle AddPassenger() - normal: PASS" << endl;
	assert(m.AddPassenger(badMan) == false);
	assert(m.GetPassengersCount() == 2);
	assert(m.GetPassenger(A)->GetName() == p14->GetName());
	assert(m.GetPassenger(A)->GetWeight() == p14->GetWeight());
	assert(m.GetPassenger(B)->GetName() == p15->GetName());
	assert(m.GetPassenger(B)->GetWeight() == p15->GetWeight());
	cout << "Test Motorcycle AddPassenger() - over maximum passenger: PASS" << endl;
	assert(m.GetDriveSpeed() == 0);
	cout << "Test Motorcycle GetDriveSpeed() - normal: PASS" << endl;
	assert(m.GetMaxSpeed() == 0);
	cout << "Test Motorcycle GetMaxSpeed() - normal: PASS" << endl;
	
	Sedan sedan1;
	assert(sedan1.GetPassengersCount() == 0);
	assert(sedan1.GetMaxPassengersCount() == 4);
	cout << "Test Sedan constructor: PASS" << endl;
	assert(sedan1.AddTrailer(new Trailer(50)));
	cout << "Test Sedan AddTrailer() - normal: PASS" << endl;
	assert(sedan1.AddTrailer(new Trailer(60)) == false);
	cout << "Test Sedan AddTrailer() - not added another trailer: PASS" << endl;
	
	Person* p17 = new Person(NAMES[A], WEIGHTS[A]);
	Person* p18 = new Person(NAMES[B], WEIGHTS[B]);
	Person* p19 = new Person(NAMES[C], WEIGHTS[C]);
	Person* p20 = new Person(NAMES[D], WEIGHTS[D]);
	Sedan sedan2;
	assert(sedan2.AddPassenger(p17));
	assert(sedan2.AddPassenger(p18));
	assert(sedan2.AddPassenger(p19));
	assert(sedan2.AddPassenger(p20));
	assert(sedan2.GetPassengersCount() == 4);
	assert(sedan2.GetMaxPassengersCount() == 4);
	cout << "Test Sedan AddPassenger() - add to 4 people: PASS" << endl;
	assert(sedan2.AddPassenger(badMan) == false);
	cout << "Test Sedan AddPassenger() - over maximum passenger: PASS" << endl;
	assert(sedan2.GetDriveSpeed() == 380);
	assert(sedan2.GetMaxSpeed() == 380);
	cout << "Test Sedan GetDriveSpeed(): PASS" << endl;
	Trailer* trailer1 = new Trailer(100);
	sedan2.AddTrailer(trailer1);
	assert(sedan2.GetDriveSpeed() == 300);
	cout << "Test Sedan AddTrailer(): PASS" << endl;
	assert(sedan2.RemoveTrailer());
	assert(sedan2.GetDriveSpeed() == 380);
	assert(sedan2.RemoveTrailer() == false);
	cout << "Test Sedan RemoveTrailer(): PASS" << endl;
	
	unsigned int testBoundaries[13][2] =
	{
		{0, 480},
		{79, 480},
		{80, 480},
		{81, 458},
		{159, 458},
		{160, 458},
		{161, 400},
		{259, 400},
		{260, 400},
		{261, 380},
		{349, 380},
		{350, 380},
		{351, 300}
	};
	const unsigned int IDX_WEIGHT = 0;
	const unsigned int IDX_SPEED = 1;
	Sedan* sedan3 = new Sedan();
	for (unsigned int i = 0; i < 13; i++)
	{
		sedan3->AddTrailer(new Trailer(testBoundaries[i][IDX_WEIGHT]));
		assert(sedan3->GetDriveSpeed() == testBoundaries[i][IDX_SPEED]);
		cout << "Test Sedan GetDriverSpeed() - boundaries: Weight("
			<< testBoundaries[i][IDX_WEIGHT] << ")-Speed("
			<< testBoundaries[i][IDX_SPEED] << ")"
			<< ": PASS" << endl;
		sedan3->RemoveTrailer();
	}
	
	UBoat uboat1;
	assert(uboat1.GetPassengersCount() == 0);
	assert(uboat1.GetMaxPassengersCount() == 50);
	cout << "Test UBoat constructor: PASS" << endl;
	
	assert(uboat1.GetDiveSpeed() == 30);
	cout << "Test UBoat GetDiveSpeed() - no passenger: PASS" << endl;
	assert(uboat1.GetSailSpeed() == 550);
	cout << "Test UBoat GetSailSpeed() - no passenger: PASS" << endl;
	assert(uboat1.GetMaxSpeed() == 550);
	cout << "Test UBoat GetMaxSpeed() - no passenger: PASS" << endl;
	
	Person* p21 = new Person(NAMES[A], WEIGHTS[A]);
	Person* p22 = new Person(NAMES[B], WEIGHTS[B]);
	Person* p23 = new Person(NAMES[C], WEIGHTS[C]);
	Person* p24 = new Person(NAMES[D], WEIGHTS[D]);
	Person* p25 = new Person(NAMES[E], WEIGHTS[E]);
	uboat1.AddPassenger(p21);
	uboat1.AddPassenger(p22);
	uboat1.AddPassenger(p23);
	uboat1.AddPassenger(p24);
	uboat1.AddPassenger(p25);
	assert(uboat1.GetDiveSpeed() == 620);
	cout << "Test UBoat GetDiveSpeed(): PASS" << endl;
	assert(uboat1.GetSailSpeed() == 516);
	cout << "Test UBoat GetSailSpeed(): PASS" << endl;
	
	DeusExMachina* deus1 = DeusExMachina::GetInstance();
	DeusExMachina* deus2 = DeusExMachina::GetInstance();
	assert(deus1 == deus2);
	cout << "Test DeusExMachina GetInstance() - singleton: PASS" << endl;
	
	for (unsigned int i = 0; i < 10; i++)
	{
		assert(deus1->AddVehicle(new Airplane(5)));
		cout << "Test DeusExMachina AddVehicle() - count " << (i + 1) << ": PASS" << endl;
	}
	assert(deus1->AddVehicle(new Airplane(5)) == false);
	cout << "Test DeusExMachina AddVehicle() - over capacity: PASS" << endl;
	
	for (unsigned int i = 0; i < 10; i++)
	{
		assert(deus1->RemoveVehicle(0));
		cout << "Test DeusExMachina RemoveVehicle() - count " << (i + 1) << ": PASS" << endl;
	}
	assert(deus1->RemoveVehicle(0) == false);
	cout << "Test DeusExMachina RemoveVehicle() - empty: PASS" << endl;
	
	Airplane* ap25 = new Airplane(5);
	Boat* b25 = new Boat(5);
	Boatplane* bp25 = new Boatplane(5);
	Motorcycle* m25 = new Motorcycle();
	Sedan* s25 = new Sedan();
	Sedan* s26 = new Sedan();
	UBoat* ub25 = new UBoat();
	s26->AddTrailer(new Trailer(50));
	
	deus1->AddVehicle(ap25); 	// 0
	deus1->AddVehicle(b25);		// 1
	deus1->AddVehicle(bp25);	// 2
	deus1->AddVehicle(m25);		// 3
	deus1->AddVehicle(s25);		// 4
	deus1->AddVehicle(s26);		// 5
	deus1->AddVehicle(ub25);	// 6
	
	deus1->Travel(); // 모든 운송 수단이 이동
	deus1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deus1->Travel(); // Motorcycle, 두 Sedan이 이동
	deus1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deus1->Travel(); // UBoat만 빼고 전부 이동
	deus1->Travel(); // 어떤 운송 수단도 움직이지 않음
	deus1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	deus1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deus1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan이 이동
	deus1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deus1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deus1->Travel(); // 트레일러 달린 Sedan만 이동
	cout << "Test DeusExMachina Travel(): PASS" << endl;
	assert(deus1->GetFurthestTravelled() == b25);
	cout << "Test DeusExMachina GetFurthestTravelled(): PASS" << endl;
	
	delete badMan;

	return 0;
}