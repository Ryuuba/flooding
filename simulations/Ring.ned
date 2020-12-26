//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

// Created: 2020-11-16 for project flooding

package flooding.simulations;

import flooding.Flooding;

import flooding.simulations.Link;

//
// A generated network with ring topology.
//
network Ring
{
    parameters:
        int initiator;
        node[*].initiator = initiator;
    submodules:
        node[10]: Flooding {
            gates:
                port[2];
        }
    connections:
        node[0].port[0] <--> Link <--> node[1].port[1];
        node[1].port[0] <--> Link <--> node[2].port[1];
        node[2].port[0] <--> Link <--> node[3].port[1];
        node[3].port[0] <--> Link <--> node[4].port[1];
        node[4].port[0] <--> Link <--> node[5].port[1];
        node[5].port[0] <--> Link <--> node[6].port[1];
        node[6].port[0] <--> Link <--> node[7].port[1];
        node[7].port[0] <--> Link <--> node[8].port[1];
        node[8].port[0] <--> Link <--> node[9].port[1];
        node[9].port[0] <--> Link <--> node[0].port[1];
}
