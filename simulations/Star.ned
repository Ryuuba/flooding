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

// Created: 2020-11-16 for project ds.ex1.flooding

package flooding.simulations;

import flooding.Flooding;

import ned.DelayChannel;

//
// A generated network with star topology.
//
network Star
{
    parameters:
        int initiator;
        node[*].initiator = initiator;
    submodules:
        node[10]: Flooding;
    connections:
        node[9].port++ <--> DelayChannel <--> node[0].port++;
        node[9].port++ <--> DelayChannel <--> node[1].port++;
        node[9].port++ <--> DelayChannel <--> node[2].port++;
        node[9].port++ <--> DelayChannel <--> node[3].port++;
        node[9].port++ <--> DelayChannel <--> node[4].port++;
        node[9].port++ <--> DelayChannel <--> node[5].port++;
        node[9].port++ <--> DelayChannel <--> node[6].port++;
        node[9].port++ <--> DelayChannel <--> node[7].port++;
        node[9].port++ <--> DelayChannel <--> node[8].port++;
}
