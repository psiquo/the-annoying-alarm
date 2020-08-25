FROM php:7.4-apache

RUN apt-get update && apt-get -y install git unzip

COPY ./html /var/www/html

RUN cd /tmp && curl -sS https://getcomposer.org/installer | php && mv composer.phar /usr/local/bin/composer
RUN cd /var/www/html && composer require php-mqtt/client

RUN chown www-data /var/www/html/alarm.txt

EXPOSE 80
