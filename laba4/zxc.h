double perimetr(double x, double y, double z)
{
	double w = x + y + z;
	return w;
}
double ploshchadj(double x, double y, double z)
{
	double p=(x+y+z)/2;
	double e = sqrt(p * (p - x) * (p - y) * (p - z));
	return e;
}
