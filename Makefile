LDLIBS = -lglut
CFLAGS = -g -Wall -pedantic 
PROG = ray_tracer
CC = g++

OBJS = ray_tracer.o vector.o eye.o camera.o ray.o scene.o scene_object.o sphere.o light.o point_light.o directional_light.o

HDRS = ray_tracer.h vector.h eye.h camera.h ray.h scene.h scene_object.h sphere.h light.h point_light.h directional_light.h

$(PROG): $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) -o $(PROG)

%.o : %.cc $(HDRS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $<


clean:
	rm -rf *.o *.ppm $(PROG)

