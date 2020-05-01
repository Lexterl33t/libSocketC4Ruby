=begin
Bienvenue à vous dans cette nouvelle vidéo aujourd'hui je vais donc vous apprendre
du moins vous faire un speed coding sur l'api ruby.h de C afin de crée
des modules ruby puisssant depuis C. AUjourd'hui nous allons dev
un module Socket pour ruby depuis la lib sys/socket de C 

=end


require './socket_rb_c'

tcp_socket_client("127.0.0.1", "1337")