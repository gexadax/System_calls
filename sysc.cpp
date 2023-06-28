#include <iostream>
#include <sys/types.h>
#include <unistd.h>

#if defined(__linux__)
#include <sys/utsname.h>
#endif

int main() {
    // Получаем информацию о процессе
    pid_t pid = getpid();
    uid_t uid = getuid();
    gid_t gid = getgid();

    std::cout << "Информация о процессе:" << std::endl;
    std::cout << "PID: " << pid << std::endl;
    std::cout << "UID: " << uid << std::endl;
    std::cout << "GID: " << gid << std::endl;

#if defined(__linux__)
    struct utsname utsname;
    uname(&utsname);

    std::cout << std::endl;
    std::cout << "Информация об операционной системе:" << std::endl;
    std::cout << "OS name: " << utsname.sysname << std::endl;
    std::cout << "Host name: " << utsname.nodename << std::endl;
    std::cout << "OS release: " << utsname.release << std::endl;
    std::cout << "OS version: " << utsname.version << std::endl;
    std::cout << "Machine name: " << utsname.machine << std::endl;
#else
    std::cout << "Системная функция uname() работает только в Linux" << std::endl;
#endif

    return 0;
}

