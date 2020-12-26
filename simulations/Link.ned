package flooding.simulations;

channel Link extends ned.DelayChannel {
  parameters:
      delay = exponential(1s);
}