# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    plateau_generator.pl                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljouanne <ljouanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/15 16:52:44 by ljouanne          #+#    #+#              #
#    Updated: 2014/09/15 16:52:56 by ljouanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print "o";
        }
        else {
            print ".";
        }
    }
    print "\n";
}
