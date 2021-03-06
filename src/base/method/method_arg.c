
#include <stdio.h>


struct structure {
	int id;
	char name[10];
};


void value(void);
void reference(void);
void call_by_value(int a, char c);//Copy
void call_by_reference(int *a, char *c);//Refer
void call_by_array(char array[]);//Refer
void call_by_array_refer(char *array);//Refer
void call_by_str(struct structure str);//Copy
void call_by_str_refer(struct structure *str);//Refer

int
main(void) {

	value();
	printf("\n\n");
	reference();

	printf("\n\n");

	char array[] = "oitate";
	printf("%s %d %p\n", array, sizeof(array), array);
	call_by_array(array);
	call_by_array_refer(array);

	printf("\n\n");
	struct structure str = {99, "oitate"};
	printf("%d %s %d %p\n", str.id, str.name, sizeof(str), &str);
	call_by_str(str);
	call_by_str_refer(&str);
	
	return 0;

}

void value(void) {
 
	int a = 9;
	char c = 'a';
	printf("%d %p\n", a, &a);
	printf("%c %p\n", c, &c);
	
	call_by_value(a, c);

}

void reference(void) {

	char temp = 'c';
	int temp_int = 9;

	int *a = &temp_int;
	char *c = &temp;
	printf("%d %p\n", *a, a);
	printf("%c %p\n", *c, c);
	
	call_by_reference(a, c);

	printf("%d %p\n", *a, a);
	printf("%c %p\n", *c, c);

}

void call_by_value(int a, char c) {
	
	printf("%d %p\n", a, &a);
	printf("%c %p\n", c, &c);

}


void call_by_reference(int *a, char *c) {

	char temp = 'z';	
	
	printf("%d %p\n", *a, a);
	*a = *a + *a;
	printf("%c %p\n", *c, c);
	*c = temp;

}

void call_by_array(char array[]) {
	printf("%s %d %p\n", array, sizeof(array), array);
}


void call_by_array_refer(char *array) {
	printf("%s %d %p\n", array, sizeof(array), array);
}


void call_by_str(struct structure str) {
	printf("%d %s %d %p\n", str.id, str.name, sizeof(str), &str);
}

void call_by_str_refer(struct structure *str) {
	printf("%d %s %d %p\n", str->id, str->name, sizeof(str), str);
}
