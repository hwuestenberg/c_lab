// an example for an infinity loop
// used to explore the gdb debugger
int main() {
	int i;
	for(i = 0; i != 1; i = i + 2)
		i = i - 2;
	return 0;
}
