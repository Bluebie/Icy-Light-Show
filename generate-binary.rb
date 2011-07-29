File.open("binary.c", 'w') do |file|
  256.times do |num|
    file.puts "#define B" + num.to_s(2).rjust(8, "0") + " #{num}"
  end
end

File.open("pixels.c", 'w') do |file|
  256.times do |num|
    file.puts "#define px" + num.to_s(2).rjust(8, "0").gsub('0', '_').gsub('1', '8') + " #{num}"
  end
end

