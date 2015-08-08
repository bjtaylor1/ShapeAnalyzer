#ifndef CLASSITERATORPAIR
#include <iostream>

template<class T> class iteratorpair
{
public:
  iteratorpair(T _start);
  iteratorpair(T _start, T _end);
  void increment();
  void incrementTwice();
  bool neitherIs(T sequenceend) const;
  bool neitherIs(T sequenceend1, T sequenceend2) const;

  T start;
  T end; 
};

template<class T> iteratorpair<T>::iteratorpair(T _start) : start(_start), end(_start)
{
  end++; //used for sequences like start1, end1, start2, end2 etc
}

template<class T> iteratorpair<T>::iteratorpair(T _start, T _end) : start(_start), end(_end)
{
  //used for two separate sequences, start will be the one, end the other
}

template<class T> bool iteratorpair<T>::neitherIs(T sequenceend) const
{
  bool retval = start != sequenceend && end != sequenceend;
	return retval;
}

template<class T> bool iteratorpair<T>::neitherIs(T sequenceend1, T sequenceend2) const
{
  return start != sequenceend1 && end != sequenceend2;
}

template<class T> void iteratorpair<T>::increment()
{
  start++;
  end++;
}

template<class T> void iteratorpair<T>::incrementTwice()
{
	start++; start++;
	end++; end++;
}

#define CLASSITERATORPAIR
#endif

