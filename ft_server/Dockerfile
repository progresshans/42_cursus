FROM	debian:buster

RUN	apt-get update && apt-get install -y \
	vim \
	nginx \
	openssl \
	php-fpm \
	php-mysql \
	mariadb-server

EXPOSE	80 443

COPY	srcs/ ./

CMD	["bash", "init.sh"]
