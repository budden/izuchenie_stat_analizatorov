#include <cstdlib>
 
// CWE-415: Double Free
// Ошибка двойного освобождения памяти
 
static void test_free(void *p) {
 	free(p);
}
 
static void test_bar() {
	void *q = malloc(1);
 	free(q);
 	test_free(q);
}
static void test_baz() {
 	void *q = malloc(1);
 	test_free(q);
 	free(q);
}
 
static void free_mem_by_pts(int*x, int* p, int m){
 	if (p==0) {
 
}
 	else {
 	    if(x==0) {
 
 	    }
 	    else {
 			test_free(p);
 			p = 0;
 	    }
 	}
	if (m==0) {
 
 	}
 	else {
 	  test_free(x);
 	}
 
 	free(x);
 	free(p);
 }
 
 void test_path_sensitiv_no_errors(){
 	int *x = (int*) malloc(1);
 	int *p = (int*) malloc(1);
 
 	free_mem_by_pts(x, p, 0);
 	free_mem_by_pts(0, p, 0);
 	free_mem_by_pts(x, 0, 0);
 	free_mem_by_pts(0, 0, 0);
 	free_mem_by_pts(0, p, 5);
 	free_mem_by_pts(0, 0, 5);
 }
 
 void test_path_sensitiv_with_errors(){
 	int *x = (int*) malloc(1);
 	int *p = (int*) malloc(1);
 
 	free_mem_by_pts(x, p, 5); // Ошибка двойного освобождения памяти
 	free_mem_by_pts(x, 0, 5); // Ошибка двойного освобождения памяти
 }
 
 void mem_multiple_free(){
 	test_path_sensitiv_no_errors(); // Код не вызывающий ошибок
 
 	test_bar(); // Ошибка для выявления контекстно-чувствительным анализом
 	test_baz(); // Ошибка для выявления контекстно-чувствительным анализом
 
 	test_path_sensitiv_with_errors(); // Ошибка для выявления анализом, чувствительным к путям выполнения
 }
