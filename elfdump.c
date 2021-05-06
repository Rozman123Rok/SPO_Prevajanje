#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>
#include <unistd.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
// Rok Rozman

int main(int argc, char **argv){
    int fd, vrednost;

    Elf32_Ehdr hdr;

    if(argc != 2){
        printf("error");
        return 0;
    }

    fd = open(argv[1], O_RDONLY); // odpremo dat
    if(fd==-1){
        printf("Error pri odpiranju");
        return 0;
    }

    read(fd,&hdr,sizeof(hdr));
    // izpisemo magic numbers
    printf("\tMagic: %x %c %c %c %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x\n", hdr.e_ident[0], hdr.e_ident[1], hdr.e_ident[2], hdr.e_ident[3], hdr.e_ident[4], hdr.e_ident[5], hdr.e_ident[6], hdr.e_ident[7], hdr.e_ident[8], hdr.e_ident[9], hdr.e_ident[10], hdr.e_ident[11], hdr.e_ident[12], hdr.e_ident[13], hdr.e_ident[14], hdr.e_ident[15], hdr.e_ident[16]);

    // kateri tip je
    	printf("\tType: ", hdr.e_type);
	switch(hdr.e_type) {
		case ET_NONE:
			printf("An unknown type\n");
		break;
		case ET_REL:
			printf("A relocatable file\n");
		break;
		case ET_EXEC:
			printf("An executable file\n");
		break;
		case ET_DYN:
			printf("A shared object\n");
		break;
		case ET_CORE:
			printf("A core file\n");
		break;
	}
    // za katero napravo
	printf("\tMachine: ", hdr.e_machine);
	switch(hdr.e_machine) {
		case EM_NONE:
			printf("No machine\n");
		break;
		case EM_386:
			printf("Intel 80386\n");
		break;
		case EM_860:
			printf("Intel 80860\n");
		break;
		case EM_PPC:
			printf("PowerPC\n");
		break;
		case EM_ARM:
			printf("ARM\n");
		break;
		default:
			printf("Other\n");
		break;
	}
    // verzija
	printf("\tVersion: 0x%.2X\n", hdr.e_version);
    // naslov
	printf("\tEntry point address: 0x%.8X\n", hdr.e_entry);
    // odmik
	printf("\tProgram header offset: 0x%.8X\n", hdr.e_phoff);

	printf("\tSection header offset: 0x%.8X\n", hdr.e_shoff);

	printf("\tFlags: 0x%.8X\n", hdr.e_flags);

	printf("\tSize of this header: 0x%X\n", hdr.e_ehsize);

	printf("\tSize of program headers: 0x%X\n", hdr.e_phentsize);

	printf("\tNumber of program headers: %d\n", hdr.e_phnum);

	printf("\tSize of section headers: 0x%X\n", hdr.e_shentsize);

	printf("\tNumber of section headers: %d\n", hdr.e_shnum);

	printf("\tSection header string table index: 0x%X\n", hdr.e_shstrndx);



    close(fd);

    return 0;
}
