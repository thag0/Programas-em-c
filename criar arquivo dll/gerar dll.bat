cls
@set /p NOMEARQUIVO=Digite o nome do arquivo .c mas sem extensao:

gcc -c %NOMEARQUIVO%.c -o %NOMEARQUIVO%.o
gcc -shared -o %NOMEARQUIVO%.dll %NOMEARQUIVO%.o

cls
@echo compilacao finalizada.
@pause