#define MAX_SIZE 100
typedef struct data
{
	char name[20];
	int age;
	char sex[20];
	char address[20];

}data;
typedef struct Contact
{
	data person[MAX_SIZE];
	int sz;
}Con;
void add(Con* pc);

void delete(Con* pc);

void display(Con* pc);
