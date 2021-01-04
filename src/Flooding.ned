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

package flooding;

//
// TODO auto-generated type
//
simple Flooding
{
    parameters:
        @display("i=device/laptop;is=n");
        // The index of the node starting the experiment
        int initiator = default(0);
        // The data attachted to the message
        int data;
        // The time at which the first message is sent
        double startTime @unit(s);
    gates:
        // This is a port supporting bidirectional communications
        inout port[];
}
