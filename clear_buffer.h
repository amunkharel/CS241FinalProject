void clear_buffer() { while( getchar() != '\n' ) {} }

void delete_endline(char * input)
{
    int i;
    int length = strlen(input);
    input[length - 1] = '\0';
}