int main(void)
{
	double	k = 3.141562;
	long long dpart;
	int		j;

	dpart = (int)k;
	k -= dpart;
	k *= 10;
	dpart *= (int)k;
}
