#include <stdio.h>
#include <math.h>

int main() {
// Kell ide valami I/O függvény, ami r-t és gr-t kiolvassa egy csv-ből
double r[] = {1.0, 1.5, 2, 2.5, 3};
double gr[] = { 0.0, 0.0, 2.0, 2.0, 0.0 };
double Ndens[] = 0.5

double q[len];
//q tömb kitöltéséhez szükséges paraméterek
//Majd a felhasználó fogja megadni
double dq=1, min=1.0, max=20.0;
int len = (max - min) / dq;

for (int i = 0; i <= len; i++) {
	q[i] = min + i * dq;
}
// csak teszteleshez kell majd
for (int i = 0; i <= len; i++) {
	printf(q[i]);
	//q és r mátrixok Descartes szorzatának és
	//szinuszának kiszámítása és tárolása
	struct qr{
		double q[];
		double r[];
		//nested loopal Descartes szorzat
		double qrmat[] = q X r;
	};
	for (int i = 0; i <= len_qrmat; i++) {
		sinqr[i] = sin(qr.qrmat);
	}
	// rgr kiszámítása
	for (int i = 0; i <= len_r) {
		rgr[i] = r[i] * (gr[i] - 1)
	}
	// Sq érték kiszámítása

	for (int i = 0; i <= len_q) {
		Double sq[i] = 4*pi*Ndens*dq/q* sinqr X rgr
	}
	//a végén pedig kiprinteli q-sq-t csv-be



}




return 0;
}
