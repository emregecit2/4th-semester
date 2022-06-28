N = 4147;
lambda_automobile_number = 50;
lambda_truck_number = 10;
lambda_automobile_weight = 0.15;
alpha_automobile_weight = 190;
lambda_truck_weight = 0.01;
alpha_truck_weight = 110;  
TotalWeight=zeros(N,1);

function y = poisscdf(x, lambda)
  sum = 0;
  for i=0:x;
    sum = sum + lambda**i / factorial(i);
  end
  y = sum * e**-lambda;
end
function x = poissrand(lambda)
  U = rand;
  x = 0;
  while U > poisscdf(x, lambda);
    x = x + 1;
  end
end

function x = gammarand(alpha, lambda)
  x = sum(-1/lambda * log(rand(alpha, 1)));
end

for k=1:N;
  automobile_number = poissrand(lambda_automobile_number);
  for i=1:automobile_number;
    TotalWeight(k) = TotalWeight(k) + gammarand(alpha_automobile_weight, lambda_automobile_weight);
  end
  truck_number = poissrand(lambda_truck_number);
  for i=1:truck_number;
    TotalWeight(k) = TotalWeight(k) + gammarand(alpha_truck_weight, lambda_truck_weight);
  end
end
fprintf("Probability that the total weight of all the vehicles that pass over the bridge on a day is more than 200 tons = %f\n", mean(TotalWeight > 200000));
fprintf("Estimated total weight = %f\n", mean(TotalWeight));
fprintf("Standard deviation = %f\n", std(TotalWeight));