#!/bin/bash

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=cadet/CN=localhost" -keyout /etc/ssl/private/localhost.dev.key -out /etc/ssl/certs/localhost.dev.crt

service mysql start

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "UPDATE mysql.user SET plugin = 'mysql_native_password' WHERE user='root';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES" | mysql -u root --skip-password

mv default /etc/nginx/sites-available/

tar -xvf wordpress.tar.gz
mv wordpress/ /var/www/html/
chown -R www-data /var/www/*
mv wp-config.php /var/www/html/wordpress/wp-config.php

tar -xvf phpmyadmin.tar.gz
mv phpMyAdmin-5.0.2-all-languages/ phpmyadmin/
mv phpmyadmin/ /var/www/html/
mv config.inc.php /var/www/html/phpmyadmin/config.inc.php

service php7.3-fpm start
service nginx start
bash
