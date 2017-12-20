/**
* Source: Own
*/

typedef complex<double> cd;
typedef pair<cd,double> circle;

cd intersect(circle a, circle b, int x = 0) { 
    double d = sqrt(norm(a.f-b.f));
    double co = (a.s*a.s+b.s*b.s-d*d)/(2*a.s*b.s);
    double theta = acos(co);
    
    cd tmp = (b.f-a.f)/d;
    if (x == 0) return a.f+tmp*a.s*polar(1.0,theta);
    return a.f+tmp*a.s*polar(1.0,-theta);
}

double arc(circle x, cd a, cd b) {
	cd d = (a-x.f)/(b-x.f);
	return x.s*acos(d.real());
}

int main() {
	cout << intersect({0,2},{1,1}) << "\n";
	cout << arc({0,1},cd(1,0),cd(0,1));
}