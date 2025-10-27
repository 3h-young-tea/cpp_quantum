#include<cstdbool>
#include<cstdio>
#include<array>
#include<complex>
#include<iostream>
#include<random>

#ifndef	tea_quantum_hpp

#define	tea_quantum_hpp

namespace tea{

typedef	struct	_qubit{
	std::complex<double>a,b;
}	qubit;

void	normalize(qubit *q){
	double norm=std::sqrt(std::norm(q->a)+std::norm(q->b));
	if(norm>0)
		q->a/=norm,q->b/=norm;
}

void	hadamard(qubit *q){
	std::complex<double>a,b;
	a=(q->a+q->b)/std::sqrt(2.0);
	b=(q->a-q->b)/std::sqrt(2.0);
	q->a=a,q->b=b;
}

void	x_gate(qubit *q){
	std::swap(q->a,q->b);
}

void	y_gate(qubit *q){
	std::complex<double>a,b;
	a=q->b,b=-q->a;
	q->a=a,q->b=b;
}

void	z_gate(qubit *q){
	q->b=-q->b;
}

auto	collapse(qubit *q)->_Bool{
	static std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<double>dist(0.0,1.0);
	double p0=std::norm(q->a);
	_Bool jqk=dist(rng)<p0;
	q->a=jqk,q->b=!jqk;
	return jqk;
}

typedef	struct	_qubit2{
	std::array<std::complex<double>,4>a;
	void	normalize(void);
}	qubit2;

void	qubit2::normalize(void){
	double norm = 0;
	for(auto &x:a)
		norm+=std::norm(x);
	if(norm>0)
		for(auto &x:a)
			x/=std::sqrt(norm);
}

void	hadamard(qubit2 *q,long t){
	std::array<std::complex<double>,4>b=q->a;
	for(long i=0;i<4;i++)
		if((i&1<<t)==0){
			long j=i|1<<t;
			b[i]=(q->a[i]+q->a[j])/std::sqrt(2.0);
			b[j]=(q->a[i]-q->a[j])/std::sqrt(2.0);
		}
	q->a=b;
}

void	x_gate(qubit2 *q,long t){
	std::array<std::complex<double>,4>b=q->a;
	for(long i=0;i<4;i++)
		b[i^1<<t]=q->a[i];
	q->a=b;
}

void	cnot(qubit2 *q,long c,long t){
	std::array<std::complex<double>,4>b=q->a;
	for(long i=0;i<4;i++)
		if(i&1<<c)
			b[i^1<<t]=q->a[i];
	q->a=b;
}

void	print(std::ostream &opt,const qubit2 &q){
	const char* fmt[4]={"|00>","|01>","|10>","|11>"};
	for(long i=0;i<4;i++)
		opt<<fmt[i]<<": "<<q.a[i]<<"\n";
	opt<<std::flush;
}

void	print(std::FILE *opt,const qubit2 &q){
	const char* fmt[4]={"|00>","|01>","|10>","|11>"};
	for(long i=0;i<4;i++)
		std::fprintf(opt,"%s: (%lf,%lf)\n",fmt[i],q.a[i].real(),q.a[i].imag());
}

}

#endif
