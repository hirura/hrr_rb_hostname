# HrrRbHostname

[![Build Status](https://travis-ci.com/hirura/hrr_rb_hostname.svg?branch=master)](https://travis-ci.com/hirura/hrr_rb_hostname)
[![Gem Version](https://badge.fury.io/rb/hrr_rb_hostname.svg)](https://badge.fury.io/rb/hrr_rb_hostname)

hrr_rb_hostname is a wrapper around gethostname and sethostname for CRuby.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'hrr_rb_hostname'
```

And then execute:

    $ bundle install

Or install it yourself as:

    $ gem install hrr_rb_hostname

## Usage

The basic usage is as follows.

```ruby
require "hrr_rb_hostname"

HrrRbHostname.get               # => "currenthostname"
HrrRbHostname.set "newhostname" # => "newhostname"
HrrRbHostname.get               # => "newhostname"
```

### Getting hostname

The .get and .gethostname methods return the current hostname as same as hostname command.

```ruby
HrrRbHostname.get         # => "currenthostname"
HrrRbHostname.gethostname # => "currenthostname"
```

#### Setting hostname

The .set and .sethostname methods set hostname and return the set hostname.

```ruby
HrrRbHostname.set "newhostname"         # => "newhostname"
HrrRbHostname.sethostname "newhostname" # => "newhostname"
```

## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake spec` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/hirura/hrr_rb_hostname. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [code of conduct](https://github.com/hirura/hrr_rb_hostname/blob/master/CODE_OF_CONDUCT.md).


## License

The gem is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).

## Code of Conduct

Everyone interacting in the HrrRbHostname project's codebases, issue trackers, chat rooms and mailing lists is expected to follow the [code of conduct](https://github.com/hirura/hrr_rb_hostname/blob/master/CODE_OF_CONDUCT.md).
