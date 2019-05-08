#define GRAAL
#include <iostream>
#include <iterator>
#include <cstring>
#include "../include/graal.h"

using byte = unsigned char;

/// A função encontra e retorna a primeira ocorrência do menor elemento no intervalo [first, last)
const void *graal::min( const void *first, const void *last, size_t sz, Compare cmp )
{
	const byte *menor = (const byte*) first;	
	const byte *it = (const byte*) first;		
	// Para comecar da segunda posicao
	it += sz;	

	while(it!=last)
	{	
		if(cmp(it, menor))
			// Guarda o menor valor
			menor = it;		

		// Próxima posicao do array
		it += sz;
	} 

	return menor;
}

/// A funcao inverte a ordem dos elementos do vetor no intervalo [first, last)
void *graal::reverse( void *first, void *last, size_t sz )
{
	byte *aux = new byte[sz];

	// Ponteiros para first e last
	byte *it = (byte*) first;
	byte *at = (byte*) last;

	while(it<at)
	{
		// Faz a troca dos elementos 
		std::memcpy(aux, it, sz);
		std::memcpy(it, at, sz);
		std::memcpy(at, aux, sz);

		// Próxima posicao do first
		it += sz;

		// Posicao anterior do last
		at -= sz;
	}

	return aux;	
}

/// A funcao copia os valores do intervalo em um novo array
void *graal::copy( const void *first, const void *last, const void *d_first, size_t sz )
{
	byte *it = (byte*) first;
	byte *at = (byte*) last;

	byte *d_it = (byte*) d_first;

	// Aponta para o endereco após o ultimo elemento do intervalo [first, last)
	byte *d_at = (byte*) d_it;

	while(it!=at)
	{
		// Copia o valor do endereco it para d_it
		std::memcpy(d_it, it, sz);

		// Proxima posicao do array
		it += sz;
		d_it += sz;

		d_at = d_it;
	}

	d_at += sz;

	// Retorna o ponteiro para o endereco que contem a copia do intervalo
	return d_at;
}

/// A funcao recebe um intervalo [first; last) e retorna um ponteiro para um novo array contendo a copia do intervalo original
void *graal::clone( const void *first, const void *last, size_t sz )
{
	byte *it = (byte*) first;
	byte *at = (byte*) last;

	// Calculando o tamanho do array original
	int dis = (at-it)/sz;

	// Novo array
	byte *array = new byte[dis*sz];

	while(it!=at)
	{
		// Copiando o valor de it para array
		std::memcpy(array, it, sz);

		// Proxima posicao
		it += sz;
		array += sz;
	}

	return array;
}

/// A funcao recebe um intervalo e retorna um ponteiro para o primeiro elemento encontrado que retornar true no predicado p
const void *graal::find_if( const void *first, const void *last, size_t sz, Predicate p )
{
	const byte *it = (const byte*) first;
	const byte *at = (const byte*) last;   

	while(it!=at)
	{
		// Comparo se o valor de first eh true no predicado
		if(p(it))
			return it;

		it += sz;
	}

	return at;
}

/// A funcao recebe um intervalo [first; last) e um elemento alvo, e retorna o primeiro ponteiro que for igual ao elemento alvo
const void *graal::find( const void *first, const void *last, size_t sz,
		const void *value, Equal eq )
{
	const byte *it = (const byte*) first;
	const byte *at = (const byte*) last;
	const byte *alvo = (const byte*) value;

	while(it!=at)
	{
		// Comparo se o valor em it eh igual ao alvo
		if(eq(it, alvo))
		{
			const byte *ret = it;
			return ret;
		}

		it += sz;
	}

	return at;
}

/// A funcao retorna true quando o predicado p eh verdadeiro para todos os elementos do intervalo [first; last)
bool graal::all_of( const void *first, const void *last, size_t sz, Predicate p )
{
	byte *it = (byte*) first;
	byte *at = (byte*) last;

	while(it!=at)
	{
		// Confere se o predicado de pelo menos um elemento eh falso, caso seja retorna false  
		if(!p(it))
			return false;

		// Proxima posicao do array
		it += sz;
	}

	// Caso o intervalo esteja vazio, retorna true
	if((at-it)/sz==0)
		return true;

	// Retorna true caso para todos elementos o predicado seja true 
	return true;
}

/// A funcao retorna true quando o predicado p for verdadeiro para pelo menos um elemento do intervalo [first; last)
bool graal::any_of( const void *first, const void *last, size_t sz, Predicate p )
{
	byte *it = (byte*) first;
	byte *at = (byte*) last;

	while(it!=at)
	{
		// Confere se o predicado de pelo menos um elemento eh true, caso seja retorna true  
		if(p(it))
			return true;

		// Proxima posicao do array
		it += sz;
	}

	// Caso o intervalo esteja vazio, retorna true
	if((at-it)/sz==0)
		return true;

	// Retorna false caso para nenhum elemento do intervalo o predicado seja true 
	return false;
}

/// A funcao retorna true quando o predicado p nao retornar true para nenhum elemento do intervalo [first; last)
bool graal::none_of( const void *first, const void *last, size_t sz, Predicate p )
{
	byte *it = (byte*) first;
	byte *at = (byte*) last;

	while(it!=at)
	{
		// Confere se o predicado de pelo menos um elemento eh true, caso seja retorna false  
		if(p(it))
			return false;

		// Proxima posicao do array
		it += sz;
	}

	// Caso o intervalo esteja vazio, retorna true
	if((at-it)/sz==0)
		return true;

	// Retorna true caso para todos os elementos do intervalo o predicado nao seja true 
	return true;
}

// TODO: equal

// TODO: unique

/// A funcao recebe um intervalo e reordena os elementos do intervalo de forma que todos os elementos que para o predicado p retornam true precedem os elementos que retornam false
void *graal::partition( void *first, void *last, size_t sz, Predicate p )
{
	byte *aux = (byte*) first;
	byte *it = (byte*) first;
	byte *at = (byte*) last;

	while(it!=at)
	{
		if(p(it))
		{
			// Variavel auxiliar para a troca
			byte aux2[sz];
			// Fazendo a troca dos elementos
			std::memcpy(aux2, aux, sz);
			std::memcpy(aux, it, sz);
			std::memcpy(it, aux2, sz);

			aux += sz;
		}
		// Proxima posicao do array
		it += sz;
	}
	return aux;
}

// TODO: sort
