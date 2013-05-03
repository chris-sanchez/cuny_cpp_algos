class Rat{
	private:
	int num;
	int denom;
	
	public:
	Rat(int n, int d);
	Rat(int n);
	Rat();
	
	void output() const;
	void input();
	const Rat reduce() const;
	
	int getNum() const;			//accessors
	int getDenom() const;
	void setNum(int n);		//mutators
	void setDenom(int d);
};

const Rat operator +(const Rat& r1, const Rat& r2);
const Rat operator -(const Rat& r1, const Rat& r2);
const Rat operator *(const Rat& r1, const Rat& r2);
