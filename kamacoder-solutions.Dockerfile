FROM archlinux:latest

ENV TZ=Asia/Taipei

RUN curl -LSs https://kazusa.me/dotfiles | sh

RUN pacman -Sy --needed --noconfirm gcc gdb make cmake ninja clang nodejs

USER kazusa

ENTRYPOINT ["sleep" ,"infinity"]
