#fix our stack getting a huge amount of failed requests


exec {'replace':
  provider => shell,
  command  => 'sudo sed -i "s/ULIMIT=\"-n 15\"/ULIMIT=\"-n 4096\"/" /etc/default/nginx',
  before   => Exec['restart'],
}

#restart ingnex
exec {'restart':
  provider => shell,
  command  => 'sudo service nginx restart',
}
