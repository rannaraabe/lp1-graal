#ifndef GRAAl
#define GRAAL

#include <iostream>
#include <iterator> 
#include <cstring>

namespace graal
{
	// Definindo os "apelidos" para algumas funcoes que vamos usar
	using Compare = bool (*)(const void *, const void *);
	using Predicate = bool (*)(const void *);
	using Equal = bool (*)(const void *, const void *);

	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array;
	 * cmp: funcao binária que retorna true se o primeiro  elemento foi menor do que o segundo elemento analisado;
	 */
	const void *min( const void *first, const void *last, size_t sz, Compare cmp );

	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array; 
	 */
	void *reverse( void *first, void *last, size_t sz );

	/* fisrt, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array 
	 * d_first: poteiro que indica a nova posicao para fazer a colagem dos elementos 
	 */
	void *copy( const void *first, const void *last, const void *d_first, size_t sz );

	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array; 
	 */
	void *clone( const void *first, const void *last, size_t sz );

	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array;
	 * p: predicado unário que retorna verdadeiro para o elemento requerido;
	 */
	const void *find_if( const void *first, const void *last, size_t sz, Predicate p );

	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array;
	 * value: valor para comparar os elementos;
	 * eq: funcao binária que retorna true se os elementos forem iguais, e false para outro resultado;
	 */
	const void *find( const void *first, const void *last, size_t sz,
			const void *value, Equal eq );

	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array;
	 * p: predicado unário que retorna verdadeiro para o elemento requerido;
	 */
	bool all_of( const void *first, const void *last, size_t sz, Predicate p );

	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array;
	 * p: predicado unário que retorna verdadeiro para o elemento requerido;
	 */
	bool any_of( const void *first, const void *last, size_t sz, Predicate p );

	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array;
	 * p: predicado unário que retorna verdadeiro para o elemento requerido;
	 */
	bool none_of( const void *first, const void *last, size_t sz, Predicate p );

	// TODO: equal

	// TODO: unique
	
	/* first, last: intervalo de elementos para analisar;
	 * sz: tamanho em bytes de cada elemento do array;
	 * p: predicado unário que retorna verdadeiro para o elemento requerido;
	 */
	void *partition( void *first, void *last, size_t sz, Predicate p );

	// TODO: sort
}
#endif
