class crossinfo
{
public:
	float order;
	int height;
	crossinfo(float _order, int _height);
};

int operator<(const crossinfo& c1, const crossinfo& c2);
